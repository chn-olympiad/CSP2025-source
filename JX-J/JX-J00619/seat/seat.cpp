#include <bits/stdc++.h>
using namespace std;
//easy~
struct stu{
	int grade;
	int id;
}a[128];

bool cmp(stu l,stu r){
	return l.grade>=r.grade;
}
//custom sort

int counter=0;
bool doFunctions(int vari,int varj){
	if(a[counter].id==1){
		cout<<varj+1<<' '<<vari+1;
		counter++;
		return true;
	}
	counter++;
	return false;
}//same code
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[0].grade;
	a[0].id=1;
	for(int i=1;i<n*m;i++){
		cin>>a[i].grade;
		a[i].id=2;
	}
	sort(a,a+(n*m),cmp);
	for(int j=0;j<=m;){
		for(int i=0;i<n;i++)
			if(doFunctions(i,j))
				return 0;
		j++;
		for(int i=n-1;i>=0;i--)
			if(doFunctions(i,j))
				return 0;
		j++;
	}
	cout<<"error! :(\nif u see this, we cant find XiaoR's seet";
	return 1;
}