#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	int n,k;
	fin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	int count=0;
	if(k<=1){
		int s=k;
		for(int i=0;i<n;i++){
			if(a[i]==s){
				count++;
			}
		}
		fout<<count;
		return 0;
	}
	int v=a[0];
	int l=0;
	for(int i=0;i<n;i++){
		if(v>k){
			l++; 
			i=l;
			v=a[i];
		}
		if(v==k||a[i]==k){
			count++;
			v=a[i];
			l=i+1;
		}else{
			v=v|a[i];
		} 
	}
	fout<<count;
	fin.close();
	fout.close();
	return 0;
}
