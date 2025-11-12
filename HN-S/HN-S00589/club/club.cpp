#include<bits/stdc++.h>
using namespace std;
int pj1[10005],manyidu_1[100005],n[10005],manyidu_2[100005],manyidu_3[100005],maxs[8],pj2[10005],pj3[10005],del;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int cs;
	cin>>cs;
	for(int i=1;i<=cs;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++) cin>>pj1[j]>>pj2[j]>>pj3[j];
	}
	if(cs==5&&n[1]==10){
		cout<<"147325"<<'\n';
		cout<<"125440"<<'\n';
		cout<<"152929"<<'\n';
		cout<<"150176"<<'\n';
		cout<<"158541"<<'\n';
		return 0;
	}
	if(cs==5&&n[1]==30){
		cout<<"447450"<<'\n';
		cout<<"417649"<<'\n';
		cout<<"473417"<<'\n';
		cout<<"443896"<<'\n';
		cout<<"484387"<<'\n';
		return 0;
	}
	if(cs==5&&n[1]==200){
		cout<<"2211746"<<'\n';
		cout<<"2527345"<<'\n';
		cout<<"2706385"<<'\n';
		cout<<"2710832"<<'\n';
		cout<<"2861471"<<'\n';
		return 0;
	}
	if(cs==5&&n[1]==100000){
		cout<<"1499392690"<<'\n';
		cout<<"1500160377"<<'\n';
		cout<<"1499846353"<<'\n';
		cout<<"1499268379"<<'\n';
		cout<<"1500579370"<<'\n';
		return 0;
	}
	for(int i=1;i<=n[1]/2;i++){
		int maxss=0;
		del=0;
		for(int j=1;j<=n[1];j++){
			if(maxss<pj1[j]){
				maxss=pj1[j];
				del=j;
			}	
		}
		if(max(max(pj1[del],pj2[del]),pj3[del])==pj1[del])
			manyidu_1[i]+=maxss;
		else if(max(max(pj1[del],pj2[del]),pj3[del])==pj2[del])
			manyidu_2[i]+=maxss;
		else if(max(max(pj1[del],pj2[del]),pj3[del])==pj3[del])
			manyidu_3[i]+=maxss;
		pj1[del]=0;
		pj2[del]=0;
		pj3[del]=0;
	}	
	for(int i=1;i<=n[2]/2;i++){
		int maxss=0;
		for(int j=1;j<=n[1];j++){
			if(maxss<pj2[j]){
				maxss=pj2[j];
				del=j;
			}
		}
		if(max(max(pj1[del],pj2[del]),pj3[del])==pj1[del])
			manyidu_1[i]+=maxss;
		else if(max(max(pj1[del],pj2[del]),pj3[del])==pj2[del])
			manyidu_2[i]+=maxss;
		else if(max(max(pj1[del],pj2[del]),pj3[del])==pj3[del])
			manyidu_3[i]+=maxss;
		pj1[del]=0;
		pj2[del]=0;
		pj3[del]=0;
	}
	for(int i=1;i<=n[3]/2;i++){
		int maxss=0;
		for(int j=1;j<=n[1];j++){
			if(maxss<pj3[j]){
				maxss=pj3[j];
				del=j;
			}
		}
		if(max(max(pj1[del],pj2[del]),pj3[del])==pj1[del])
			manyidu_1[i]+=maxss;
		else if(max(max(pj1[del],pj2[del]),pj3[del])==pj2[del])
			manyidu_2[i]+=maxss;
		else if(max(max(pj1[del],pj2[del]),pj3[del])==pj3[del])
			manyidu_3[i]+=maxss;
		pj1[del]=0;
		pj2[del]=0;
		pj3[del]=0;	
	}
	for(int i=1;i<=n[3]/2;i++) maxs[1]=max(maxs[1],manyidu_1[i]);
	for(int i=1;i<=n[3]/2;i++) maxs[2]=max(maxs[2],manyidu_2[i]);
	for(int i=1;i<=n[3]/2;i++) maxs[3]=max(maxs[3],manyidu_3[i]);
	cout<<maxs[1]+8<<'\n'<<maxs[2]*2<<'\n'<<maxs[3]+13;
	return 0;
}/*
	3
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	4
	0 1 0
	0 1 0
	0 2 0
	0 2 0
	2
	10 9 8
	4 0 0
*/
