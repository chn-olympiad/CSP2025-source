#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,q,cnt,pos;
string b,a,s,tmp;
map<string,string> dic;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>b>>a;
		dic[b]=a;
	}
	while(q--){
		cin>>b>>a;
		cnt=0;
		for(int i=0;i<=b.size();i++){
			s="";
			for(int j=i;j<=b.size();j++){
				s+=b[j];
				if(dic.count(s)){
					tmp=b;
					pos=0;
					for(int k=i;k<=j;k++)tmp[k]=dic[s][pos++];
					if(tmp==a) cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

