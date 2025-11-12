#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],o,qzh[500005],ye,p;

ifstream fin("xor.in");
ofstream fout("xor.out");

int yihuohe(int a,int b){
	int r=0,w=0;
	while(a||b){
		r+=((a%2+b%2)%2)*pow(2,w);
		a/=2;b/=2;
		w++;
	}
	return r;
}

int main(){
	fin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		qzh[i]=yihuohe(qzh[i-1],a[i]);
	}
	cout<<endl;
	p=1;o=0;
	while(p<=n){
		ye=0;
		for(int i=p;i<=n;i++){
			for(int j=p;j<i;j++){
				if(yihuohe(qzh[i],qzh[j])==k){
					ye=1;
					o++;
					break;
				}
			}
			if(ye==1){
				p=i+1;
				break;
			}
		}
		if(ye==0){
			break;
		}	
	}
	fout<<o;
	fin.close();
	fout.close();
}
