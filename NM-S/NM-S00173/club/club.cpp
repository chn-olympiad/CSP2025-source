#include <bits/stdc++.h>
using namespace std;
int x,y,a[100001],b[100001],c[100001];
set< pair<int,int> >am,bm,cm;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	scanf("%d",&x);
	for(int i=0;i<x;i++){
		scanf("%d",&y);
		for(int k=0;k<y;k++){
			scanf("%d%d%d",&a[k],&b[k],&c[k]);
			if(a[k]>=b[k] and a[k]>=c[k]){
				am.insert(make_pair(a[k]-max(b[k],c[k]),k));
			}
			else if(b[k]>=a[k] and b[k]>=c[k]){
				bm.insert(make_pair(b[k]-max(a[k],c[k]),k));
			}
			else{
				cm.insert(make_pair(c[k]-max(b[k],a[k]),k));
			}
		}
		if((int)am.size()>=(int)bm.size() and bm.size() >=(int)cm.size()){
			while((int)am.size()>y/2){
				if(b[am.begin()->second] >= c[am.begin()->second]){
					bm.insert(make_pair(b[am.begin()->second]-c[am.begin()->second],am.begin()->second));
					am.erase(am.begin());
				}
				else{
					cm.insert(make_pair(c[am.begin()->second],am.begin()->second));
					am.erase(am.begin());
				}
			}
			while((int)bm.size()>y/2){
				cm.insert(make_pair(c[bm.begin()->second],bm.begin()->second));
				bm.erase(bm.begin());
			}
		}
		else if((int)am.size()>=(int)cm.size() and cm.size()>=(int)bm.size()){
			while((int)am.size()>y/2){
				if(b[am.begin()->second] > c[am.begin()->second]){
					bm.insert(make_pair(b[am.begin()->second],am.begin()->second));
					am.erase(am.begin());
				}
				else{
					cm.insert(make_pair(c[am.begin()->second]-b[am.begin()->second],am.begin()->second));
					am.erase(am.begin());
				}
			}
			while((int)cm.size()>y/2){
				bm.insert(make_pair(b[cm.begin()->second],cm.begin()->second));
				cm.erase(cm.begin());
			}
		}
		else if((int)bm.size()>=(int)am.size() and am.size()>=(int)cm.size()){
			while((int)bm.size()>y/2){
				if(a[bm.begin()->second] > c[bm.begin()->second]){
					am.insert(make_pair(a[bm.begin()->second]-c[bm.begin()->second],bm.begin()->second));
					bm.erase(bm.begin());
				}
				else{
					cm.insert(make_pair(c[bm.begin()->second],bm.begin()->second));
					bm.erase(bm.begin());
				}
			}
			while((int)am.size()>y/2){
				cm.insert(make_pair(c[am.begin()->second],am.begin()->second));
				am.erase(am.begin());
			}
		}
		else if((int)bm.size()>=(int)cm.size() and cm.size()>=(int)am.size()){
			while((int)bm.size()>y/2){
				if(a[bm.begin()->second] >= c[bm.begin()->second]){
					am.insert(make_pair(a[bm.begin()->second],bm.begin()->second));
					bm.erase(bm.begin());
				}
				else{
					cm.insert(make_pair(c[bm.begin()->second]-a[bm.begin()->second],bm.begin()->second));
					bm.erase(bm.begin());
				}
			}
			while((int)cm.size()>y/2){
				am.insert(make_pair(a[cm.begin()->second],cm.begin()->second));
				cm.erase(cm.begin());
			}
		}
		else if((int)cm.size()>=(int)bm.size() and bm.size()>=(int)am.size()){
			while((int)cm.size()>y/2){
				if(a[cm.begin()->second] > b[cm.begin()->second]){
					am.insert(make_pair(a[cm.begin()->second],cm.begin()->second));
					cm.erase(cm.begin());
				}
				else{
					bm.insert(make_pair(b[cm.begin()->second]-a[cm.begin()->second],cm.begin()->second));
					cm.erase(cm.begin());
				}
			}
			while((int)bm.size()>y/2){
				am.insert(make_pair(a[bm.begin()->second],bm.begin()->second));
				bm.erase(bm.begin());
			}
		}
		else{

			while((int)cm.size()>y/2){
				if(a[cm.begin()->second] >= b[cm.begin()->second]){
					am.insert(make_pair(a[cm.begin()->second]-b[cm.begin()->second],cm.begin()->second));
					cm.erase(cm.begin());
				}
				else{
					bm.insert(make_pair(b[cm.begin()->second],cm.begin()->second));
					cm.erase(cm.begin());
				}
			}

			while((int)am.size()>y/2){
				bm.insert(make_pair(b[am.begin()->second],am.begin()->second));
				am.erase(am.begin());
			}
		}
		int u=0;
		for(auto k=am.begin();k!=am.end();k++){
			u+=a[k->second];
		}

		for(auto k=bm.begin();k!=bm.end();k++){
			u+=b[k->second];
		}

		for(auto k=cm.begin();k!=cm.end();k++){
			u+=c[k->second];
		}
		am.clear();
		bm.clear();
		cm.clear();
		printf("%d\n",u);
	}
	return 0;
}

