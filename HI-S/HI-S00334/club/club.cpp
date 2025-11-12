#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int start;
	int end;
}per;
bool compare(per a,per b){
	return a.end<b.end;
}
int main(){
	int n;
	cin>>n;
	per a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].start>>a[i].end;
	}
	/*int a[n][2];
	for(int i=0;i<n;i++){
	 for(int j=0;j<2;j++){
	 	cin>>a[i][j];
	 }
	}*/
	sort(a,a+n,compare);
	int sum=1;
	int finalend=a[0].end;
	for(int i=1;i<n;i++){
	if(a[i].start>=finalend){
		sum++;
		finalend=a[i].end;
		}
	}
	cout<<sum;
}
 
