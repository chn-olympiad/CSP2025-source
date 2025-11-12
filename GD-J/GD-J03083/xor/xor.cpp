#include<bits/stdc++.h>
using namespace std;
int n,m,l[500005]={},l1[500005]={},l0[500005]={},s,j,y;
int main(){
	freopen("xor4.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&l[i]);
	}
	if(m==0){
		sort(l,l+n);
		j=0;
		int k=0;
		for(int i=0;i<n-1;i++){
			if(l[i]==-1){
				continue;
			}
			if(l[i]==l[i+1]){
				s+=1;
				l[i]=-1;
				l[i+1]=-1;
			}
			else if(l[i]==0){
				l0[k]=0;
				k++;
			}
			else{
				l1[j]=l[i];
				j++;
			}
		}
		s+=j/4;
		if(j%4>=2 && k>=1){
			s+=1;
			k-=1;
		}
		s+=k;
		printf("%d",s);
	}
	else if(m==1){
		y=1;
		int k;
		while(y==1){
			j=0;
			k=0;
			for(int i=0;i<n-1;i++){
				if(l[i]==-1){
					continue;
				}
				if(l[i]!=l[i+1]){
					s+=1;
					l[i]=-1;
					l[i+1]=-1;
				}
				else if(l[i]==1){
					l0[k]=1;
					k++;
				}
				else{
					l1[j]=l[i];
					j++;
				}
			}
			if(l[n-1]!=-1){
				l1[j]=l[n-1];
				j++;
			}
			y=0;
			for(int i=1;i<=j;i++){
				if(l1[i]!=l1[0]){
					y=1;
					break;
				}
			}
			if(y==1){
				for(int i=0;i<j;i++){
					l[i]=l1[i];
					n=j;
				}
			}
			else{
				s+=k;
			}
		}
		printf("%d",s);
	}
	return 0;
}
