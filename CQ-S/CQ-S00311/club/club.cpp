#include<bits/stdc++.h>
#define dick_dick long long
#define s_dick struct
#define dickt return
#define dicker for
#define dickf if
using namespace std;
dick_dick DICK;
dick_dick d_i_c_k,d_i_c_k1=0,d_i_c_k2=0,d_i_c_k3=0,_d_i_c_k_=0;
s_dick dick
{
	dick_dick _d_i_c_k_1,_d_i_c_k_2,_d_i_c_k_3;
}DicK[100005];
dick_dick di_ck1[100005],di_ck2[100005],di_ck3[100005];
dick_dick dick_1(dick_dick dick1,dick_dick dick2)
{
	dickt DicK[dick1]._d_i_c_k_1-max(DicK[dick1]._d_i_c_k_2,DicK[dick1]._d_i_c_k_3)<DicK[dick2]._d_i_c_k_1-max(DicK[dick2]._d_i_c_k_2,DicK[dick2]._d_i_c_k_3);
}
dick_dick dick_2(dick_dick dick1,dick_dick dick2)
{
	dickt DicK[dick1]._d_i_c_k_2-max(DicK[dick1]._d_i_c_k_1,DicK[dick1]._d_i_c_k_3)<DicK[dick2]._d_i_c_k_2-max(DicK[dick2]._d_i_c_k_1,DicK[dick2]._d_i_c_k_3);
}
dick_dick dick_3(dick_dick dick1,dick_dick dick2)
{
	dickt DicK[dick1]._d_i_c_k_3-max(DicK[dick1]._d_i_c_k_1,DicK[dick1]._d_i_c_k_2)<DicK[dick2]._d_i_c_k_3-max(DicK[dick2]._d_i_c_k_1,DicK[dick2]._d_i_c_k_2);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>DICK;
	while(DICK--)
	{
		d_i_c_k1=0,d_i_c_k2=0,d_i_c_k3=0,_d_i_c_k_=0;
		cin>>d_i_c_k;
		dicker(dick_dick Dick=1;Dick<=d_i_c_k;Dick++)
		{
			cin>>DicK[Dick]._d_i_c_k_1>>DicK[Dick]._d_i_c_k_2>>DicK[Dick]._d_i_c_k_3;
			dickf(DicK[Dick]._d_i_c_k_1==max({DicK[Dick]._d_i_c_k_1,DicK[Dick]._d_i_c_k_2,DicK[Dick]._d_i_c_k_3}))
			{
				di_ck1[++d_i_c_k1]=Dick;
				_d_i_c_k_+=DicK[Dick]._d_i_c_k_1;
			}
			else dickf(DicK[Dick]._d_i_c_k_2==max({DicK[Dick]._d_i_c_k_1,DicK[Dick]._d_i_c_k_2,DicK[Dick]._d_i_c_k_3}))
			{
				di_ck2[++d_i_c_k2]=Dick;
				_d_i_c_k_+=DicK[Dick]._d_i_c_k_2;
			}
			else
			{
				di_ck3[++d_i_c_k3]=Dick;
				_d_i_c_k_+=DicK[Dick]._d_i_c_k_3;
			}
		}
		dickf(d_i_c_k1>d_i_c_k/2)
		{
			sort(di_ck1+1,di_ck1+d_i_c_k1+1,dick_1);
			dicker(dick_dick Dick=1;Dick<=d_i_c_k1-d_i_c_k/2;Dick++)
			{
				_d_i_c_k_-=DicK[di_ck1[Dick]]._d_i_c_k_1-max(DicK[di_ck1[Dick]]._d_i_c_k_2,DicK[di_ck1[Dick]]._d_i_c_k_3);
			}
		}
		dickf(d_i_c_k2>d_i_c_k/2)
		{
			sort(di_ck2+1,di_ck2+d_i_c_k2+1,dick_2);
			dicker(dick_dick Dick=1;Dick<=d_i_c_k2-d_i_c_k/2;Dick++)
			{
				_d_i_c_k_-=DicK[di_ck2[Dick]]._d_i_c_k_2-max(DicK[di_ck2[Dick]]._d_i_c_k_1,DicK[di_ck2[Dick]]._d_i_c_k_3);
			}
		}
		dickf(d_i_c_k3>d_i_c_k/2)
		{
			sort(di_ck3+1,di_ck3+d_i_c_k3+1,dick_3);
			dicker(dick_dick Dick=1;Dick<=d_i_c_k3-d_i_c_k/2;Dick++)
			{
				_d_i_c_k_-=DicK[di_ck3[Dick]]._d_i_c_k_3-max(DicK[di_ck3[Dick]]._d_i_c_k_1,DicK[di_ck3[Dick]]._d_i_c_k_2);
			}
		}
		cout<<_d_i_c_k_<<endl;
	}
	dickt 0;
}
/*
这是我最后一次打csp了 








学了三年，最后还是在中途AFO了








已经两个月没有做题了，感觉150分够了 







所以我要打一个火箭模型
 #
 #
# # 
*/
