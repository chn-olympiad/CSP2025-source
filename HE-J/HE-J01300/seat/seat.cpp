#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct per{
	int h,l;
	int score;
	int num;
};

int n,m;
per a[101];

bool cmp(per a,per b){
	return a.score>b.score;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].num=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		a[i].l=(i+n-1)/n;
		if(a[i].l%2==1){
			if(i%n==0){
				a[i].h=n;
			}
			else{
				a[i].h=i%n;
			}
		}
		else{
			if(i%n==0){
				a[i].h=1;
			}
			else{
				a[i].h=n-i%n+1;
			}
		}
		if(a[i].num==1){
			cout<<a[i].l<<" "<<a[i].h<<endl;
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
