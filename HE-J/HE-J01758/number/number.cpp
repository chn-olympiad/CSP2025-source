#include<bits/stdc++.h>
using namespace std;
char number[1000001];
int f[1000001];
int n;
char a;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>number[i];
		}
	for(int i=0;i<n;i++){
		if(number[i]-'0'>0&&number[i]-'0'<10){
			f[i]=number[i]-'0';
		}
	}
	sort(f,f+n+1,cmp);
	for(int i=0;i<n;i++){
		if(f[i]>0)cout<<f[i]; 
	}
	
	
	
	

	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
