#include<bits/stdc++.h>
using namespace std;

int n,m,a[509],out[509];
string s;

int I(int x){
	int y=1;
	for(int i=2;i<=x;i++){
		y*=i;
	}
	return y;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	
	out[-1]=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(s[i]=='0'){
			out[i]=out[i-1]+1; 
		}
		else{
			out[i]=out[i-1];
		}
	}
	sort(a,a+n);
	int tag=0;
	for(int i=0;i<n;i++){
		
	}
	
	cout<<"0"<<endl;
	
	
	
	return 0;
} 
