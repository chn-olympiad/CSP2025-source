#include<bits/stdc++.h>
using namespace std;
struct student{
	int mark,num;
};
bool cmp(student a,student b){
	if(a.mark!=b.mark) return a.mark>b.mark;
	return a.num<b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	vector<student> x;
	student buf;
	int bufi,n,m;
	cin>>n>>m;
	x.resize(n*m+1);
	for(int i=1;i<=n*m;i++){
		cin>>bufi;
		buf.mark=bufi;
		buf.num=i;
		x.push_back(buf);
	}
	sort(x.begin()+1,x.end(),cmp);
	buf.mark=x[1].mark;buf.num=x[1].num;
	bufi=1;
	while(buf.num!=1){
		 buf.mark=x[bufi+1].mark;
		 buf.num=x[bufi+1].num;
		 bufi++;
	}
	int c=(bufi-1)/n+1,r=bufi%n;
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
