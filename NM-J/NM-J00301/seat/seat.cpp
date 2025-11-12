#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long n,m,a;
	//n=行，m=列，a=小明 
	cin>>n>>m>>a;
	long long ai[n][m];
	
	int s[105]={};
	
	for(int i=2;i<=n*m;i++){
		int w;
		cin>>w;
		s[w]++;
		
	}
	int t_n=1,t_m=1,buzhid1=0,buzhid2;
	//t_n为输出，t_m为输出，buzhid1|2表其中变化数字
	 
	bool sss=true;
	//sss表其中向上或向下的状态 
	 
	for(int i=m*n;i>=1;i--){
		if(s[i] != a && sss==true && t_n!=n){
			t_n+=1;
			
		}
		else if(t_n==n && s[i]!=a){
			t_m+=1;
			sss=false;
		
		}
		else if(s[i]!=a && sss==false && t_n!=n){
			t_n-=1;
		
		}
		else if(t_n==1 && s[i]!=a){
			t_m+=1;
			sss=true;
		
		}else if(a==s[i] && sss==true){
			cout<<cout<<t_m<<" "<<t_n+1;
			return 0;
		}
		else if(a==s[i] && sss==false){
			cout<<cout<<t_m<<" "<<t_n-1;
			return 0;
		}
	}
	cout<<t_m<<" "<<t_n;
	
	
	
	return 0;
}
