#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c,d,e;
	cin>>a>>b;
	vector<int> v;
	c=a*b;
	cin>>d;
	v.push_back(d);
	for(int i=0;i<c-1;i++){
		cin>>e;
		v.push_back(e);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<c;i++){
		if(v[i]==d){
			e=i;
			break;
		}
	}
	if(c==1){
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	int flag=0;
	e=c-e-1;
	int t=1,s=0,x=1,y=1;
	for(int i=0;i<c;i++){
		if(e==i){
			cout<<x<<" "<<y<<endl;
			return 0;
		}
		if(i==0){
			if(a!=1){
				y++;
				continue;
			}
		}
		if(y==a&&flag==0){
			x++;
			flag++;
			t=0;
			s=1;
		}
		else if(y==1&&flag==0){
			x++;
			flag++;
			t=1;
			s=0;
		}
		else if(t==0&&s==1){
			flag=0;
			y--;
		}
		else{
			flag=0;
			y++;
		}
	}
	return 0;
}
