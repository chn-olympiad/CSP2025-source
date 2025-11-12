#include <bits/stdc++.h>
using namespace std;
int n,m;
int grade[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>grade[i];
	int R=grade[1];
	sort(grade+1,grade+n*m+1);
	int ans=n*m;
	for(int i=1;i<=m;i++){
		bool flag=0;
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(grade[ans]==R){
					cout<<i<<" "<<j;
					flag=1;
					break;
				}
				ans--;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(grade[ans]==R){
					cout<<i<<" "<<j;
					flag=1; 
					break;
				}
				ans--;
			}
		}
		if(flag==1) break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
