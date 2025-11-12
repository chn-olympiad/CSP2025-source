#include<cstdio>
#include<vector>
#include<algorithm>
bool cmp(char a,char b){
	return (int)(a)>(int)(b)?true:false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,want,have=1;
	std::vector<int> w;
	scanf("%d%d%d",&x,&y,&want);
	w.push_back(want);
	for(int a(2);a<=x*y;++a){
		int now;
		scanf("%d",&now);
		have++;
		w.push_back(now);
	}
	int it=1;
	std::sort(w.begin(),w.begin()+w.size(),cmp);
	for(int a(0);a<have;++a){
//		printf("%d ",w[a]);
		if(w[a]==want) it+=a;
	}
//	printf("\n");
	int r=it/y,t=0;
	if(it%y!=0) r++;
	if(r%2==0){
		t=y-(it%y)+1;
	}
	else{
		t=it%y;
		if(t==0) t=y;
	}
	printf("%d %d",r,t);
	return 0;
}
