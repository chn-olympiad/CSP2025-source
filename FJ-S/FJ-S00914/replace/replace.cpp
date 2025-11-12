#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string s1;
	string s2;
};
node a[500];
node ques;
bool check(int i,int j){
	for(int i)
}
void work(node ques){
	int l1=0,l2=0;
	int r1=ques.s1.size()-1;
	int r2=ques.s2.size()-1;
	for(int i=0;i<r1;i++)
	{
		for(int j=i;j<r1;j++){
			if(check(i,j)){
				replace(i,j);
			}
		}
	}
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].s1>>a[i].s2;
	for(int i=1;i<=q;i++){
		cin>>ques.s1>>ques.s2;
		work(ques);
	}
	return 0;
}
