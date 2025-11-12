#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	int n;
	fin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i]<a[j]){
				int t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	int t=n,j=0,flag=0;
	for(int i=0;i<n;i++){
		int sum=0;
		int max=a[j];
		while(t!=0){
			sum=sum+a[j];
			i++;
			if(sum>2*max){
			flag++;
			}
			t--;
		}
		t=t-1;
		j=n-t;
	}
	fout<<flag*2;
	fin.close();
	fout.close();
	return 0;
}
