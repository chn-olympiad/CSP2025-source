#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
	int x,num;
}a[1000];
bool cmp(edge a,edge b){
	return a.num>b.num;
}
void abab(int i){
	if(i%n==0){
		cout<<i/n<<" "<<n<<"\n"; 
	}
	else{
		cout<<i/n+1<<" "<<i%n<<"\n";
	}
}
void ab(int i){
	if(i%n==0){
		cout<<i/n<<" "<<n-i%n+1<<"\n";
	}
	else{
		cout<<i/n+1<<" "<<n-i%n+1<<"\n";
	}
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].x=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].x==1){
			if(i%n==0){
				if((i/n)%2==1){
					abab(i);
				}
				else{
					ab(i);
				}
			}
			else{
				if((i/n+1)%2==1){
					abab(i);
				}
				else{
					ab(i);
				}
			}
			break;
		}
	}	
	return 0;
}
