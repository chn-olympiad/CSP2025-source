#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[111][111],b[100005];
long long s,sum,w,q=1;
int cmp(int c,int d){
	return c>d;
}
bool f=0;
void S(int x,int y,int e){
	if(e==w){
		cout<<y<<' '<<x;
		f=1;
		return;
	}
	if(x==1){
		return;
	}
	a[x][y]=e;
	q++;
	S(x-1,y,e+1);
}

void N(int x,int y,int e){
	if(e==w){
		cout<<y<<' '<<x;
		f=1;
		return;
	}
	if(x==n){
		return;
	}
	a[x][y]=e;
	q++;
	N(x+1,y,e+1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>b[i];
	}
	s=b[1];
	
	sort(b+1,b+sum+1,cmp);
	
	for(int i=1;i<=sum;i++){
		if(b[i]==s){
			w=i;
			break;
		}
	}
	
    a[1][1]=1;
    
    for(int i=1;i<=m;i++){
    	if(i%2==1){
    		N(1,i,q);
    		q++;
    		if(f==1){
    			return 0;
			}
		}
		else{
			S(n,i,q);
			q++;
			if(f==1){
				return 0;
			}
		}
	}
	return 0;
}
