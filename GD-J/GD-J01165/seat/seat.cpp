#include<bits/stdc++.h>
using namespace std;
struct stu{
	int c;bool z;
	stu(int ic,bool iz){c=ic,z=iz;}
	stu(int n){c=n,z=false;}
};
vector<stu> v;
bool cmp(stu a,stu b){
	return a.c>b.c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int c;
	cin>>c;
	v.push_back(stu(c,true));
	for(int i=1;i<m*n;i++) cin>>c,v.push_back(stu(c));
	sort(v.begin(),v.end(),cmp);
	int a=0;
	for(int i=0;i<v.size();i++) if(v[i].z){
		a=i;
		break;
	}
	int y=a/m,x=a%m;
	cout<<y+1<<" "<<(y%2?m-x:x+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
