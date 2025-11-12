#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string sa[N],sb[N],ta,tb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>sa[i]>>sb[i];
	for(int i=1;i<=q;i++){
		long long sum=0;
		cin>>ta>>tb;
		for(int j=1;j<=n;j++){
			for(int a=0;a<ta.size();a++){
				if(ta.size()-a<sa[j].size()) break;
				bool op=1;
				for(int b=0;b<sa[j].size();b++){
					if(ta[a+b]!=sa[j][b]){
						op=0;
						break;
					} 
				}
				if(!op) continue;
				string tc;
				for(int b=0;b<ta.size();b++) tc[b]=ta[b];
				for(int b=0;b<sa[j].size();b++){
					ta[a+b]=sb[j][b];
				}
				if(ta==tb){
					sum++;
					for(int b=0;b<ta.size();b++) ta[b]=tc[b];
					break;
				}
				for(int b=0;b<ta.size();b++) ta[b]=tc[b];
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}

