#include<bits/stdc++.h>
using namespace std;//dp no fangcheng wo wa ka na i,ko no tanxin,ya ppari ka su ne.
struct cake114514{
	int c1,c2,c3;
}member[114514];
int t,n,cl1,cl2,cl3,suki;
bool cmp1(cake114514 x,cake114514 y){
	return x.c1>y.c1;
}

bool cmp2(cake114514 x,cake114514 y){
	return x.c2>y.c2;
}

bool cmp3(cake114514 x,cake114514 y){
	return x.c3>y.c3;
}

void solve(){
	cl1=0,cl2=0,cl3=0,suki=0;
	cin>>n;
	int l=n/2;
	for(register int i=0;i<n;i++){
		cin>>member[i].c1>>member[i].c2>>member[i].c3;
	}
	sort(member,member+n,cmp2);
	for(register int i=0;i<n;i++){
		if(member[i].c1>member[i].c2&&member[i].c1>member[i].c3&&cl1<l)
		{
			if(cl1<l){
				cl1++;
			suki+=member[i].c1;
			continue;	
			}
		
		}
		if(member[i].c2>member[i].c1&&member[i].c2>member[i].c3&&cl2<l)
		{
			if(cl2<l){
				cl2++;
			suki+=member[i].c2;
			continue;	
			}
		}
		if(member[i].c3>member[i].c1&&member[i].c2<member[i].c3&&cl3<l)
		{
			if(cl3<l){
				cl3++;
			suki+=member[i].c3;
			continue;	
			}
		}
		if(member[i].c1>member[i].c3||member[i].c1>member[i].c2&&cl1<l){
			if(cl1<l){
			cl1++;
			suki+=member[i].c1;	
			continue;	
			}
			
		}
		if(member[i].c2>member[i].c1||member[i].c2>member[i].c3&&cl2<l){
			if(cl2<l){
				cl2++;
			suki+=member[i].c2;
			continue;	
			}
		}
		if(member[i].c2>member[i].c1||member[i].c2>member[i].c3&&cl3<l){
			if(cl3<l){
				cl3++;
			suki+=member[i].c3;
			continue;	
			}
	}
	}
	cout<<suki;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	solve();
	return 0;
}
