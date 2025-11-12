# include <iostream>
using namespace std;
int n, t, m;
int arr[10010][3];
int cl[] = {0, 0, 0};
int ans[10];


int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	
	cin>>t;
	n=t;
	
	while(n>0){
		cin>>m;
		int cmax = m/2;
		//cout<<cmax<<"\n";
		for(int i=0;i<m;i++){
			cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
		}
		for(int i=0;i<m;i++){
			int anst=0;
			int u=0; //Ë÷Òý 
			for(int j=2;j>0;j--){
				if(arr[i][j]>arr[i][u] && cl[j]+1<=cmax){
					u=j;
				}
			}
			cl[u]++;
			ans[t-n] += arr[i][u];
		}
		--n;
	}
	
	for(int i=0;i<t;i++){
		cout<<ans[i]<<"\n";
	}
	
	return 0;
}







