#include<bits/stdc++.h> 
using namespace std;
long long n,m;
int cnt;
int c,r=1;
int s[15][15];
/*void ch(int m){
		string cv;
	while(m!=0){
		int t3;
		t3=m%2;
		cv+=t3;
		cv+=' ';
		m/=2;
	}}
void f(int a,int b,string m){
	string cu;
	while(a!=0&&b!=0){
	if(a%2==b&2&&a%2==0) {
	cu+='0';
	cu+=' ';
	a/=2;
	b/=2;
	}
	else {
	cu+='1';
	cu+=' ';
	a/=2;
	b/=2;
	}}
	
	if(m==cu) return 1;
	else return 0;


}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	vector<int>a(n);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m){
			a[i]=0;
			a[i]-=1;
			cnt++;}
	}
	
	for(int i=1;i<=n;i++){
		int sum=a[1];
		int as;
	for(int j=i+1;j<=n;j++){
		if(a[j]!=-1&&a[i]!=-1 && sum!=-1){
			as=a[j];
			if(sum|as==m){
				cnt++;
				break;}
			else {
				sum+=as;
				continue;}
		}
		else break;
	}}
	cout<<cnt;
	return 0;
}
