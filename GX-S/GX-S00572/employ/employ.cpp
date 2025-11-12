#include<bits/stdc++.h>
using namespace std;
const long long MAXN=998244353;
int a[550];
int score[550];
long long n,m,zero=0,one=0,cnt=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
	}
	for(int i=1;i<=n;i++)cin>>score[i];
	sort(a+1,a+n+1);
	do{
		vector<bool> s(550,false);
		int x=0;
		int sum=0,num=0;
		while(x<=n){
			for(;x<=n;x++){
				if(s[x]==false)break;
			}
			if(a[x]==0){x++;num++;s[x]=true;}
			for(int i=x;i<n;i++){
				if(score[i]>0){
					score[i]-=num;
				}
				else{
					s[i]=true;
				}
			}
			if(sum>=m){
				cnt++;
				cnt%=MAXN;
				continue;
			}
			num=0;
			x++;
		}
		
	}while(next_permutation(a+1,a+n+1));
	cout<<cnt%MAXN;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
