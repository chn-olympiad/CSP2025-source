#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct stu{
	int score;
	bool t=0;
}b[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n*m;i++){
		scanf("%d",&b[i].score);
		b[1].t=1;
	}
	
	bool temp=1;
	for(int i=1;i<=n*m;i++){
		if(temp&&i==2)break;
		for(int j=i+1;j<=n*m;j++){
			if(b[j].score>b[i].score){
				swap(b[i].score,b[j].score); 
				swap(b[i].t,b[j].t);
				temp=0;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(b[i].t)k=i;
	}
//	cout<<k<<endl;
	if(double(k)/double(m)>k/m)cout<<k/m+1<<" "<<k%n;
	else cout<<k/m<<" "<<k%n;
	return 0; 
} 
