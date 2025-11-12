#include<bits/stdc++.h>
using namespace std;
int b[5001],result = 0;
bool c = true;
vector<int> x();
int paixu(int w,int y){
	for(int i = 0;i<=0;i++){
		x.push_back(b[i]);
		
	}
}
int Research(int n,int m){
	for(int i = n;i<m;i++){
		paixu(i,m)
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	for(int i = 0;i<a;i++) cin>>b[i];
	for(int i = 0;i<a-1;i++){
		for(int j =0;j<a-1;j ++){
			int w = b[j],y = b[j+1];
			b[j] = max(w,y);
			b[j+1] = min(w,y);
		}
	}
	Research(3,a);
	return 0;
}

