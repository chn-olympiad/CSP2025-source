#include<bits/stdc++.h>
using namespace std;
//Òì»ò·ûºÅÊÇÉ¶°¡°¡°¡°¡°¡°¡(TAT) 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(int l=0;l<n;l++){
		for(int i=0;i<n-l;i++){
			int x=a[i];
			for(int j=i+1;j<i+l;j++){
				x+=a[j];
			}//cout<<i+1<<' '<<i+1+l<<' '<<x<<endl;
		}
	}while(1){
		
	}
	return 0;
}

