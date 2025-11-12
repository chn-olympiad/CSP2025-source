#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;

struct Note{
	int x;
	int y;
};

bool cmp(Note a,Note b){
	return a.y<b.y;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d",n);
	scanf("%d",k);
	//cin>>n>>k;
	int s[N] = {0};
	for(int i=0;i<n;i++){
		scanf("%d",s[i]);
	}
	Note a[N];
	int num = 0;//a.size()
	for(int i=0;i<n;i++){//l
		int yhh = s[i];
		for(int j=i;j<n;j++){//r
			yhh = yhh|s[j];
			if(yhh == k){
				a[num].x = i;
				a[num].y = j;
			}
		}
	}
	int tot = 0;
	sort(a,a+num,cmp);
	//cout<<a[0].x;
	for(int i=0;i<num;i++){
		tot++;
		if(a[i+1].y!=0 && a[i+1].y<a[i].y)
			a[i+1].x = 0,a[i+1].y = 0;
	} 
	printf("%d",tot);//<<tot;
	return 0;
}