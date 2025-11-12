#include<bits/stdc++.h>
using namespace std;

struct people{
	int a,b,c;
	int change_lost;
	people (int _a=0,int _b=0,int _c=0,int _change_lost=0){
		a=_a;
		b=_b;
		c=_c;
		change_lost=_change_lost;
	}
};

int t;
void run();
bool cmp(people a,people b);
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){
		run();
	}
	return 0;
} 
void run(){
	int n,ans=0;
	scanf("%d",&n);
	int Max=n/2;
	vector<people> vec_a;
	vector<people> vec_b;
	vector<people> vec_c;
	for (int i=1;i<=n;i++){
		people temp_p;
		scanf("%d %d %d",&temp_p.a,&temp_p.b,&temp_p.c);
		int Max_p=max(temp_p.a,max(temp_p.b,temp_p.c));
		ans+=Max_p;
		if (Max_p==temp_p.a){
			temp_p.change_lost=Max_p-max(temp_p.b,temp_p.c);
			vec_a.push_back(temp_p);
		}
		else if (Max_p==temp_p.b){
			temp_p.change_lost=Max_p-max(temp_p.a,temp_p.c);
			vec_b.push_back(temp_p);
		}
		else if (Max_p==temp_p.c){
			temp_p.change_lost=Max_p-max(temp_p.a,temp_p.b);
			vec_c.push_back(temp_p);
		}
	}
	if (vec_a.size()>Max){
		sort(vec_a.begin(),vec_a.end(),cmp);
		for (int i=vec_a.size()-1;i>=Max;i--){
			ans-=vec_a[i].change_lost;
		}
	}
	else if (vec_b.size()>Max){
		sort(vec_b.begin(),vec_b.end(),cmp);
		for (int i=vec_b.size()-1;i>=Max;i--){
			ans-=vec_b[i].change_lost;
		}
	}
	else if (vec_c.size()>Max){
		sort(vec_c.begin(),vec_c.end(),cmp);
		for (int i=vec_c.size()-1;i>=Max;i--){
			ans-=vec_c[i].change_lost;
		}
	}
	printf("%d\n",ans);
}
bool cmp(people a,people b){
	return a.change_lost>b.change_lost;
}
