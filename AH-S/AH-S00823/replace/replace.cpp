#include<bits/stdc++.h>
using namespace std;
int n,q,sum;
string a1;
struct node{
	string s1,s2;
}a[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	cin>>a1;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size();
		for(int i=0;i<len;i++){
			int j=0,v=0;
			if(t1[i]==a[i].s1[j]){
				int len2=a[i].s1.size();
				while(j<=len2){
					if(t1[j]==a[i].s1[j]){
						v=1;
						j++;
					}
					else{
						v=0;
						break;
					}
				}
			}
			if(v==1)sum++;
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
