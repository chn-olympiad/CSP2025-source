#include<bits/stdc++.h>
using namespace std;
struct ad{
	int value1,value2,value3,cla;
};
bool cmp(ad a,ad b){
	if(a.cla==1){
		return a.value1-max(a.value2,a.value3)>b.value1-max(b.value2,b.value3);
	}else if(a.cla==2){
		return a.value2-max(a.value1,a.value3)>b.value2-max(b.value1,b.value3);
	}else{
		return a.value3-max(a.value1,a.value2)>b.value3-max(b.value1,b.value2);
	}
}
int t,n;
vector<ad>d1,d2,d3;
ad a[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		d1.clear(),d2.clear(),d3.clear();
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i].value1,&a[i].value2,&a[i].value3);
			if(a[i].value1>max(a[i].value2,a[i].value3)){
				a[i].cla=1;
				d1.push_back(a[i]);
			}else if(a[i].value2>a[i].value3){
				a[i].cla=2;
				d2.push_back(a[i]);
			}else{
				a[i].cla=3;
				d3.push_back(a[i]);
			}
		}
		if(d1.size()>n/2){
			sort(d1.begin(),d1.end(),cmp);
			while(d1.size()>n/2){
				ad p=d1.at(d1.size()-1);
				d1.pop_back();
				if(p.value2>p.value3){
					p.cla=2;
					d2.push_back(p);
				}else{
					p.cla=3;
					d3.push_back(p);
				}
			}
		}
		if(d2.size()>n/2){
			sort(d2.begin(),d2.end(),cmp);
			while(d2.size()>n/2){
				ad p=d2.at(d2.size()-1);
				d2.pop_back();
				if(p.value1>p.value3){
					p.cla=1;
					d1.push_back(p);
				}else{
					p.cla=3;
					d3.push_back(p);
				}
			}
		}
		if(d3.size()>n/2){
			sort(d3.begin(),d3.end(),cmp);
			while(d3.size()>n/2){
				ad p=d3.at(d3.size()-1);
				d3.pop_back();
				if(p.value2>p.value1){
					p.cla=2;
					d2.push_back(p);
				}else{
					p.cla=1;
					d1.push_back(p);
				}
			}
		}
		int ans=0;
		for(int i=0;i<d1.size();i++){
			ans+=d1[i].value1;
		}for(int i=0;i<d2.size();i++){
			ans+=d2[i].value2;
		}for(int i=0;i<d3.size();i++){
			ans+=d3[i].value3;
		}
		printf("%d\n",ans);
	}
	return 0;
}
