#include <bits/stdc++.h>
using namespace std;
int n,x,qwe=0,nox[3][100005],noxx[3]={0,0,0};
void txt(int a,int s,int asd){
	if (noxx[a]<=x/2-1){
		asd+=nox[a][s];
		noxx[a]++;
	}
	else return;
	if (s>=x){
	    if (asd>qwe)
			qwe = asd;
		noxx[a]--;
		return ;
	}
	for (int i=0;i<3;i++){
		txt(i,s+1,asd);
	}
	noxx[a]--;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;
    for (int l=0;l<n;l++){
		qwe=0;
		cin>>x;
		for (int i=0;i<x;i++)
		    cin>>nox[0][i]>>nox[1][i]>>nox[2][i];
		for (int i=0;i<3;i++)
		    txt(i,0,0);
		cout<<qwe<<endl;
    }
}
