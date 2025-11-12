#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Stu{
	int p;
	int k;
}stu[1000001];
bool cmp(Stu x,Stu y){
	return x.p>y.p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>stu[i].p;
		stu[i].k=i;
	}
	sort(stu+1,stu+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(stu[i].k==1){
			int row=(i-1)/n+1;
			int cot=(i-1)%n+1;
			if(row%2==0) {
				cot=n-cot+1;
			}
			cout<<row<<" "<<cot<<endl;
			return 0;
		}
	}



} 
// empty
