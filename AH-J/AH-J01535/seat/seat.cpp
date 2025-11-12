#include<bits/stdc++.h>
using namespace std;
int n,m;
typedef struct Stu{
	int grade,num;
}Stu;
Stu a[105];
bool cmp(Stu x,Stu y){
	return x.grade>y.grade;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].grade;
		a[i].num=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int num;
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			num=i;
		}
	}
	if(((num+n-1)/n)%2==1){
		cout<<(num+n-1)/n<<" "<<(num-1)%n+1<<endl;
	}else{
		cout<<(num+n-1)/n<<" "<<n-(num%n)+1<<endl;
	}
	return 0;
}
