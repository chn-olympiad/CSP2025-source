#include<bits/stdc++.h>
using namespace std;
int t;
int cnt=0,c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		int n;
		cin>>n;
		int a[100005][5];
		bool flat=true;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[3]!=0){
				flat=false;
			}
		}
		cnt=0;
		if(flat==true){
			for(int i=1;i<=n;i++){
				c[i]=a[i][1]+100005-a[i][2];
			}
			sort(c+1,c+n+1);
			for(int i=1;i<=n;i++){
				cnt+=a[i][2];
				if(i>n/2){
					i-=100005+c[i];
				}
			}
			cout<<cnt;
		}
		else{
			for(int i=1;i<=n;i++){
				cnt+=max(a[i][1],max(a[i][2],a[i][3]));
			}
			cout<<cnt;
		}
		cout<<endl;
	}
	return 0;
}
