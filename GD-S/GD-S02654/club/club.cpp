#include <iostream>
#include <vector>
using namespace std;
unsigned int t,n;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct hpy {
	int c1;
	int c2;
	int c3;
};
vector<hpy> happy;
void sort1(unsigned int start,unsigned int end) {
	if((start+1)==end) {
		return;
	}
	if((start+2)==end) {
		if(happy[start].c1>=happy[end].c1)
		{
			int tmp=happy[start].c1;
			happy[start].c1=happy[end].c1;
			happy[end].c1=tmp;
		}
			return;
	}
	unsigned int mid=(start+end)/2;
	int t1=start,t2=mid;
	int cc1[mid-start],cc2[end-mid+1];
	sort1(start,mid);
	sort1(mid+1,end);
	for(int i=0;i<mid-start;i++)
	{
		cc1[i]=happy[i].c1;
	}
	for(int i=mid-start;i<end-mid;i++)
	{
		cc1[i]=happy[i].c1;
	}
	for(int i=0;i<end;i++)
	{
		if(happy[t1].c1<happy[t2].c1&&t1<(mid-start))
		{
			happy[i].c1=cc1[t1];
			t1++;
		}
		else{
			happy[i].c1=cc2[t2];
			t2++;
		}
	}
	return;
}
int sma(int c1,int c2,int c3) {
	int smallest=c1;
	if(smallest>c2) {
		smallest=c2;
	}
	if(smallest>c3) {
		smallest=c3;
	}
	return smallest;
}
int main(int argc, char** argv) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	unsigned int jg=0;
	scanf("%u",&t);
	for(int i=0; i<t; i++) {
		scanf("%d",&n);
		int rdm=n/3,rdm_value1,rdm_value2;
		happy.resize(n);
		for(int j=0; j<n; j++) {
			int c1,c2,c3,tmp;
			scanf("%d%d%d",&c1,&c2,&c3);
			tmp=sma(c1,c2,c3);
			jg+=tmp;
			happy[j].c1=c1-tmp;
			happy[j].c2=c2-tmp;
			happy[j].c3=c3-tmp;
			if(rdm==j) {
				rdm_value1=c2;
				rdm_value2=c3;
			}
		}
		if(rdm_value1==0) {
			sort1(0,n-1);
			for(int i=n-1;i>(n/2);i--)
			{
				jg+=happy[i].c1;
			}
		}
		printf("%d",jg);
	}
	return 0;
}
