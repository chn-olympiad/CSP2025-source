#include<bits/stdc++.h>
using namespace std;

long long t;
struct nd{
	int nu,ma;
}a[10010][10010];
int main(){
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int n_1 = n / 2;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin>>a[i][j].ma;
				a[i][j].nu = j
			}
		}
		
		int sum = 0,num[3];
		for(int i = 1;i <= n;i++){
			int s=max(a[i][1].ma,max(a[i][2].ma,a[i][3].ma));
			sum+=s;
			for(int j = 1;j <= 3;j++){
				if(a[i][j].ma == s)num[j]++;
				
			}
			
		}
		cout <<sum;
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
