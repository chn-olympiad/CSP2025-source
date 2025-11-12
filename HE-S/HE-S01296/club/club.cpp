#include <bits/stdc++.h>
using namespace std;
int p[10086][3];
int main(){
	freopen("club.in","r",stdin);

	int w;
	cin>>w;
	while(w--){
		int n;
		int t1=0,t2=0,t3=0;
		int sum=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>p[i][0];
			cin>>p[i][1];
			cin>>p[i][2];
			if(p[i][0]>p[i][1]&&p[i][0]>p[i][2]){
				if(t1<n/2){
					sum+=p[i][0];
					t1++;
				}else{
					p[i][0]=0;
				}
			}
			else if(p[i][1]>p[i][0]&&p[i][1]>p[i][2]){
				if(t2<n/2){
					sum+=p[i][1];
					t2++;
				}else{
					p[i][1]=0;
				}
			}
			else if(p[i][2]>p[i][1]&&p[i][2]>p[i][0]){
				if(t3<n/2){
					sum+=p[i][2];
					t3++;
				}else{
					p[i][2]=0;
				}
			}
		}
		cout<<sum;
		
	}
	freopen("club.out","w",stdout);
	return 0;
}

