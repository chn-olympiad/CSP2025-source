#include <bits/stdc++.h>
using namespace std;
int const N=10e5+10;
int t;
int mem[N][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		int a=n/2,sum=0;
		int g1=0,g2=0,g3=0;
		
		for(int i=1;i<=n;i++){
			cin>>mem[i][1]>>mem[i][2]>>mem[i][3];
		}
		for(int i=1;i<=n;i++){
			if(mem[i][1]>=mem[i][2]&&mem[i][1]>=mem[i][3]){
				if(g1<=a){
					sum+=mem[i][1];
					g1++;
				
				}else{
					if(mem[i][2]>=mem[i][3]&&g2<=a){
						g2++;
						sum+=mem[i][2];
					
					}else{
						sum+=mem[i][3];
						g3++;
						
					}
				}
			}else if(mem[i][2]>=mem[i][1]&&mem[i][2]>=mem[i][3]){
				if(g2<=a){
					sum+=mem[i][2];
					g2++;
				
				}else{
					if(mem[i][1]>=mem[i][3]&&g1<=a){
						g1++;
						sum+=mem[i][1];
					
					}else{
						sum+=mem[i][3];
						g3++;
						
					}
				}
			}else{
				if(g3<=a){
					sum+=mem[i][3];
					g3++;
				}else{
					if(mem[i][1]>=mem[i][2]&&g1<a){
						g1++;
						sum+=mem[i][1];
					}else{
						sum+=mem[i][2];
						g2++;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
