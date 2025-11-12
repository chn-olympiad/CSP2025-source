#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Person{
	int p[3];
	short focus,prefocus;
} a[100001];
bool cmd(Person a,Person b){
	return a.p[a.focus]-a.p[a.prefocus] <b.p[b.focus]-b.p[b.prefocus];
} 
void premain(){
	int total[3]={0,0,0};
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i].p[0] >> a[i].p[1] >> a[i].p[2];
		if(a[i].p[0]>=a[i].p[1]&&a[i].p[0]>=a[i].p[2]){
			a[i].focus=0;
			a[i].prefocus=(a[i].p[1]>=a[i].p[2]?1:2);
		}
		else if(a[i].p[1]>=a[i].p[0]&&a[i].p[1]>=a[i].p[2]){
			a[i].focus=1;
			a[i].prefocus=(a[i].p[0]>=a[i].p[2]?0:2);
		}
		else if(a[i].p[2]>=a[i].p[0]&&a[i].p[2]>=a[i].p[1]){
			a[i].focus=2;
			a[i].prefocus=(a[i].p[0]>=a[i].p[1]?0:1);
		}
		total[a[i].focus]++;
	}
	int s=0;
	for(int i=0;i<n;i++){
		switch(a[i].focus){
			case 0:
				s+=a[i].p[0];
				break;
			case 1:
				s+=a[i].p[1];
				break;
			case 2:
				s+=a[i].p[2];
				break;
		}
	}
	if(total[0]<=(n>>1)&&total[1]<=(n>>1)&&total[2]<=(n>>1)){
		cout << s << '\n';
	}
	else{
		sort(a,a+n,cmd);
		int k=0;
		while(!(total[0]<=(n>>1)&&total[1]<=(n>>1)&&total[2]<=(n>>1))){
			s-=a[k].p[a[k].focus]-a[k].p[a[k].prefocus];
			total[a[k].focus]--;
			total[a[k].prefocus]++;
			k++;
		}
		cout << s << '\n';
	}
	return; 
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int K;
	cin >> K;
	for(int i=0;i<K;i++)premain();
	return 0;
}
