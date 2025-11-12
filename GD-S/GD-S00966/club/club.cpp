#include<bits/stdc++.h>
using namespace std;
struct student{
	int a,b,c;
};
bool cmp(student x,student y){
	return (x.a-x.b)>(y.a-y.b);
}
student stu[100009];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int cnt;
	cin>>cnt;
	for(int i=1;i<=cnt;i++){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
			
		}
		int cnt=0;
		sort(stu+1,stu+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(i<=n/2) cnt+=stu[i].a;
			else cnt+=stu[i].b;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

