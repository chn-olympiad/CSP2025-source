#include<bits/stdc++.h>
using namespace std;

int n,m,a[10001];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int x=a[1];
	for(int i=1;i<=n*m;i++)
		for(int j=1;j<=n*m-i;j++)
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
	int h=1,l=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]!=x){
			if(l%2==1)
				if(h==n){
					l++;
				}
				else
					h++;
			else
				if(h==1)
					l++;
				else
					h--;
		}
		else
			printf("%d %d",l,h);
	}
		
} 

