#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans = 0;
	int llen = -1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
	
		int wai = a[i];
		int shu[114514];
		string b = to_string(wai);
		int len = b.size();
		int ii  = 0;
		for(;;)
		{
			int one = wai / 2;
			int two = wai % 2;
			shu[ii] = two;
			wai = one;
			llen++;
			if(one <= 0)
			{
				break;
			}
		}
		int yi[114514];
		int iiii = 0;
			
		int shu_three[114514];
		while(shu[iiii] != 0)
		{
			shu_three[llen] = shu[iiii];
			llen--;
			iiii++;
		}
		for(int j=0;j<n;j++)
		{
			int lllen =  -1;
			int shu_two[1114514];
			for(int p = 0;;p++)
			{
				int wai_two = a[p];
				string b_two  = to_string(wai);
				int len_two = b_two.size();
				int iii = 0;
				for(int q=len_two;q>=0;q--)
				{
					int one_two = wai_two / 2;
					int two_two = wai_two % 2;
					shu_two[iii] = two_two;
					wai_two = one_two;
					lllen++;
					if(one_two <= 0)
					{
						break;
					}
				}
			}
			//int yii[114514];
			int iiiii = 0;
			
			int shu_four[114514];
			while(shu_two[iiiii] != 0)
			{
				shu_four[lllen] = shu_two[iiiii];
				llen--;
				iiiii++;
			}
			int y = max(llen,lllen);
			for(int t = y;y>=0;y--)
			{
				if(shu_three[t] == 1&&shu_four[t]  ==  1) yi[t]  =  0;
				else if(shu_three[t] == 1&&shu_four[t]  == 0) yi[t]  = 1;
				else if(shu_three[t] == 0&&shu_four[t] ==  1) yi[t]  = 1;
				else yi[t] =  1;
			}
			string u;
			u  = to_string(k);
			int lennn = u.size();
			int kk  =  k;
			int sto[114514];
			int jj = 0;
			while(kk != 0)
			{
				kk /= 2;
				int kkk = kk % 2;
				sto[jj] = kkk;
				jj++;
			}
			for(int h = jj;h>=0;h--)
			{
				if(sto[h] == yi[h])
				{
					ans++;
				}
				else
				{
					break;
				}
			}

		}
	}
	cout<<ans;
}
