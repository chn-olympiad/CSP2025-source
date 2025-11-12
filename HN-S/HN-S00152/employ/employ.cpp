#include <bits/stdc++.h>
using namespace std;
int n,m,renshu[505],guoguan=0;
int main(){
	freopen("employ.in ","r",stdin);
	freopen("employ.out ","w",stdout);
	string ti;
	cin>>n>>m>>ti;
	for (int i=0;i<n;i++){
		cin>>renshu[i];
	}
	sort(renshu,renshu+n);
	for (int i=0;i<n;i++){
		int lq=0;
		for (int j=0;j<n;j++){
			if(renshu[j]<0){
				j++;
			}
			if(ti[j]=='1'){
				lq++;
			}
			for (int k=j+1;k<n;k++){
				renshu[k]=renshu[k]-1;
			}
			if(lq==m){
				guoguan++;
				break;
			}
		}
		swap(renshu[i],renshu[i+1]);
	}
	cout<<guoguan;
}
