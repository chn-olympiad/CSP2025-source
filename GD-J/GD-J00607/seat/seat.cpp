#include<bits/stdc++.h>
using namespace std;

struct cdr{
	int score;
	int id; 
}a[110];

bool cmp(cdr a,cdr b){
	return a.score > b.score;
}


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].score;
		a[i].id = i;
	}
	sort(a+1,a+1+n*m,cmp);
	
	int Liepai = 1,Hangpai = 1,bv = 1;
	for(int i=1;i<=n*m;i++){
		if(a[i].id == 1){
			cout<<Liepai<<" "<<Hangpai;
			return 0;
		}
		Hangpai += bv;
		if(Hangpai == n+1 || Hangpai == 0){
			if(Hangpai == n+1){
				Liepai++;
				bv = -1;
				Hangpai = n;
			}
			else{
				Liepai++;
				bv = 1;
				Hangpai = 1;
			}
		}
	}
	
	return 0;
}
