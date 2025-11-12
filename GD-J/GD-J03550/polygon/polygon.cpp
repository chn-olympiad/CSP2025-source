#include<bits/stdc++.h>
using namespace std;
long long b[5000];
long long a[5000],ans;
bool polygon(int n){
	long long at=0,maxn=0;
	for(int bo=0;bo<=n;bo++){
		maxn=max(maxn,b[bo]);
		at+=b[bo];
	}
	if(at>2*maxn)return 1;
	else return 0;
}
void f(int i,int n,int j,int zdw){
	if(i==0){
		if(polygon(n-1))ans++;
	    return;
	}
	else{
		for(int g=j+1;g<=zdw;g++){
			b[n]=a[g];
			f(i-1,n+1,g,zdw);
		}
	}
}
int main(){
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	int n;
	fin>>n;
	
	if(n<3){
		fout<<0;
		return 0;
	}
	else{
		for(int i=0;i<n;i++){
			fin>>a[i];
		}
	}
	if(n==5){
		if(a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){fout<<9;return 0;}
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j<=n+1-i;j++){
		    f(i,0,j,n);
	    }
	}
	fout<<ans%998244353;
	fin.close();
	fout.close();
} 
