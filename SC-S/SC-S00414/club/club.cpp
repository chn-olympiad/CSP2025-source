#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,x[100005],y,z;
	int a,s[3][2];
	cin>>t;
	while(t--){
		int maxx=-1;
		cin>>n;
		if(n==2){
			cin>>s[1][1]>>s[2][1]>>s[3][1];
			cin>>s[1][2]>>s[2][2]>>s[3][2];
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						maxx=max(maxx,s[i][1]+s[j][2]);
					}
				}
			}
			cout<<maxx<<endl;
		}else{
			int cnt=1;
			while(n--){
				cin>>x[cnt]>>y>>z;
				cnt++;
			}
			sort(x+1,x+1+cnt,cmp);
			cout<<x[1]+x[2]<<endl;
		}
	}
	return 0;
}