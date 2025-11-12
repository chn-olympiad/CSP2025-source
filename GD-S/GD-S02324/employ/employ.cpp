#include<bits/stdc++.h>
using namespace std;
int c[501];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n,cmp);
	if(m=1){
	   while(n-1!=0){
	   ans*=n;
	   n--;	
	}
	cout<<ans;
	return 0;	
	}
	if(m=n){
		for(int i=0;i<s.size;i++){
		if(s[i]=='0'){
		    cout<<"0";
		    return 0;
			}	
		}
	}
	while(n-1!=0){
	   ans*=n;
	   n--;	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
