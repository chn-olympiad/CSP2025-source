#include<bits/stdc++.h>
using namespace std;
int y[1000001];
string k;
int ans,n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>k;
	for(int i=0;i<k.size();i++){
	   if(0<=k[i]-'0'&&10>k[i]-'0'){
	   	 y[n]=k[i]-'0';
	   	 n++;
	   }	
	}
	sort(y,y+n,cmp);
	for(int i=0;i<n;i++){
		cout<<y[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
