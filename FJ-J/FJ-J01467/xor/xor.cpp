#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	freopen("xor.in",'r',stdin);
	freopen("xor.out",'w',stdout);
	int n,k;
	cin>>n>>k;
	int a[101] = {};
	int d;
	int count = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			d=i;
			count++;
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(i>d||j<d){
				int m=a[i];
				for(int x=i+1;x<=j;x++){
					m = m |!a[x];
					if(m==k){
						count++;
					}
				}
				cout<<endl;
			}
		}
	}
	cout<<count<<endl;
	fclose(stdin);
	fclose(stdout);
}
