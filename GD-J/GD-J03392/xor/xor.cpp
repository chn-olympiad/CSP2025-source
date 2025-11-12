#include <bits/stdc++.h>
using namespace std;

struct X{
	int a,len=0;
	string s,bs;
};

int main(){
	ifstream fin("D:/GD-J03392/xor/xor.in");
	ofstream fout("D:/GD-J03392/xor/xor.out");
	int n,m,won=0;
	fin>>n>>m;
	X x[n];
	for(int i=0;i<n;i++){
		fin>>x[i].a;
	}
	for(int i=0;i<n;i++){
		int temp=x[i].a,t=0;
		while(temp>1){
			x[i].s[t]=temp%2+'0';
			temp/=2,t++;
			if(temp==1)	x[i].s[t]='1';
		}
		x[i].len=t+1;
	/*	for(int j=0;j<=t;j++){
			cout<<x[i].s[j];
		}
		cout<<' ';*/
	}
	for(int j=0;j<x[0].len;j++){
		x[0].bs[j]=x[0].s[j];
	}
	fout<<x[n-2].len;
/*	for(int i=0;i<n;i++){
		for(int j=0;j<max(x[i].len,x[i+1].len);j++){
			if(j>x[i+1].len) x[i+1].bs[j]=x[i].s[j];
			else if(j>x[i].len) x[i+1].bs[j]=x[i+1].s[j];
			else{
				if(x[i].s[j]!=x[i+1].s[j]) x[i+1].bs[j]='1';
				else x[i+1].bs[j]='0';	
			}
		}
	}
	string hl;
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			for(int q=0;q<x[j].len;q++){
				if(x[i].s[q]=='1')
					hl[q]='1'-x[j].s[q]+'0';
				else
					hl[q]=x[j].s[q];
			}
			int g=1;
			for(int q=0;q<x[i].len;q++){
				sum=hl[q]*g;
				g*=2;
			}
			if(sum==m) won++;
		}
	}*/
	return 0;
}
