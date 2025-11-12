#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int p[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int shuru;
	for(int i=0;i<n;i++){
		cin>>shuru;
		a.push_back(shuru);
	}
	sort(a.begin(),a.end());
	int cishu=1;
	for(int i=0;i<n;i++){
		cishu*=2;}
	cishu-=1;
	int result=0;
	int answer;
	int maxn1;
	answer=0;
	for(int i=0; i<cishu;i++){
		p[0]+=1;
		result=0;
		maxn1=0;
		for(int j=0;j<n;j++){
			if(p[j]==2){
				p[j+1]+=1;
				p[j]=0;
						}}
		for(int j=0;j<n;j++){
			if(p[j]==1){
				result+=a[j];
				if(maxn1<a[j])maxn1=a[j];}}
		if(result>(maxn1*2)) answer+=1;}
		cout<<answer%998224353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
