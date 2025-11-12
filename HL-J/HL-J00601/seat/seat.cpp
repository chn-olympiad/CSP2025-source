#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int n,m;
int a;
int ci;
int w;
int w1,w2;
int x;//lie
int y;//hang
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	w=1;
	for(int i=1;i<=(n*m-1);i++){
		cin>>ci;
		if(a<ci){
			w++;
		}
	}
	w1=w;
	w2=w;
	//ÁÐ
	if((w1%n)!=0){
			if(w1>n){
				while(w1%n==0){
					w1++;
				}
			}else if(w1<n){
				w1=n;
			}
	}
	x=(w1-1)/n+1;
	//ÐÐ 
	if((x%2)==0){
		y=(((x+1)*n)-w2)%n+1;
	}else{
		y=n-((x*n)-w2);
	}
	
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
