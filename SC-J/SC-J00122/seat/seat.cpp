#include<bits/stdc++.h>
using namespace std;
struct stu{
	int num;
	int score;
}a[10010];
bool sp(stu x,stu y){
	return x.score>y.score;
}
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n >>m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i].score;
		a[i].num=i;
	}
	sort(a+1,a+1+n*m,sp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			int q=i/n;
			if(i>(q*n)){
				q++;
			}
			cout << q<<" ";
			int w;
			if(q%2==0){
				w=n-i%n+1;
			}else{
				w=i%n;
			}
			if(w==0){
				w=n;
			}
			cout << w;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}