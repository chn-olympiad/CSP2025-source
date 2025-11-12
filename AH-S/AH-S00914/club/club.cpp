#include<bits/stdc++.h>
using namespace std;
struct Stu
{
	int num,l1,l2,l3;
}a[100010];
bool cmp1(Stu x,Stu y){
	return x.l1-(x.l3+x.l2)>y.l1-(y.l3+y.l2);
}
bool cmp2(Stu x,Stu y){
	return x.l2-(x.l3+x.l1)>y.l2-(y.l3+y.l1);
}
bool cmp3(Stu x,Stu y){
	return x.l3-(x.l1+x.l2)>y.l3-(y.l1+y.l2);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].l1,&a[i].l2,&a[i].l3);
			a[i].num=i;
		}
		sort(a+1,a+n+1,cmp1);
		int club1s=1,club1add=0,club2s=1,club2add=0,club3s=1,club3add=0,cnt1=0,cnt2=0,cnt3=0;
		while((a[club1s].l1>=a[club1s].l2&&a[club1s].l1>=a[club1s].l3)&&cnt1<n/2)
			if(a[club1s].l1!=-0x3f)
			{
				cnt1++;
				club1add+=a[club1s].l1;
				a[club1s].l1=-0x3f;
				a[club1s].l2=-0x3f;
				a[club1s++].l3=-0x3f;
			}
			else club1s++;
		sort(a+1,a+n+1,cmp2);
		while((a[club2s].l2>=a[club2s].l1&&a[club2s].l2>=a[club2s].l3)&&cnt2<n/2)
			if(a[club2s].l2!=-0x3f)
			{
				cnt2++;
				club2add+=a[club2s].l2;
				a[club2s].l1=-0x3f;
				a[club2s++].l3=-0x3f;
			}
			else club2s++;
		sort(a+1,a+n+1,cmp3);
		while((a[club3s].l3>=a[club3s].l1&&a[club3s].l3>=a[club3s].l2)&&cnt3<n/2)
			if(a[club3s].l3!=-0x3f)
			{
				cnt3++;
				club3add+=a[club3s].l3;
				a[club3s].l1=-0x3f;
				a[club3s++].l2=-0x3f;
			}
			else club3s++;
		int elseadd=0;	
		for(int i=1;i<=n;i++)
		{
			if(a[i].l1!=-0x3f)
			{
				
				int el1=a[i].l1,el2=a[i].l2,el3=a[i].l3;
		
				if(el1>el2&&el1>el3&&cnt1<n/2)
				{
					cnt1++;
					elseadd+=el1;
				}
				else if(el2>el1&&el2>el3&&cnt2<n/2)
					{
						cnt2++;
						elseadd+=el2;
					}
					else if(el3>el2&&el3>el2&&cnt3<n/2)
						{
							cnt3++;
							elseadd+=el3;
						}
						else if(cnt1<n/2) cnt1++,elseadd+=el1;
						else if(cnt2<n/2) cnt2++,elseadd+=el2;
						else if(cnt3<n/2) cnt3++,elseadd+=el3;
			}
		}
			
		cout<<club1add+club2add+club3add+elseadd<<endl;
		
	}
}
