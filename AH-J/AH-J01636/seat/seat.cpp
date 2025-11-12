#include<bits/stdc++.h>
using namespace std;
int s[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=0,cnt=0,f=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>s[cnt++];
		}
	}
	x=s[0];
	sort(s,s+cnt,cmp);
	cnt=0;
	for(int i=1;i<=n;i++){
		if(f==1)break;
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(s[cnt]==x){
					cout<<i<<" "<<j;
					f=1;
					cnt++;
				}
				else cnt++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(s[cnt]==x){
					cout<<i<<" "<<j;
					f=1;
					cnt++;
				}
				else cnt++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
