#include<bits/stdc++.h>
using namespace std;
long long n ,k ,pd =1,pd2=1,tmp1 =0,fh=1,yx=0;
long long arr[1100];
long long ans =0,sum=0;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    
    cin >>n >>k;
    for(int i =1;i <=n;i ++)
    {
        cin >>arr[i];
        if(arr[i] !=1) pd=0;
        if(arr[i] <0||arr[i] >1) pd2=0;
        if(arr[i] ==1) tmp1++;
    }
    if(pd &&k ==0) 
    {
        cout <<n/2;
        return 0;
    }
    if(pd2 &&(k >=0 &&k <=1))
    {
        if(k ==0)
        {
            cout <<tmp1 /2;
            return 0;
        }
        if(k ==1)
        {
            cout <<tmp1;
            return 0;
        }
    }
    for(int i =1;i <=n;i ++)
    {
        if(arr[i] ==k)
        {
            sum =0;
            ans++;
            fh =1;
        }
        else 
        {
            if(arr[i] ==0)
            {
				if((arr[i +1] /arr[i -1]) %2 ==0)
				{
					fh  =1;
				}
				else
				{
					fh =-1;
				}
				continue;
            }
            else if(i +1<=n)
            {
				if(arr[i +1] /arr[i] %2 ==0)
				{
					fh  =1;
				}
				else
				{
					fh =-1;
				}
			}
			
            sum +=fh *arr[i];
            if(sum <0) sum *=-1;
            if(sum ==k)
            {
                ans++;
                sum =0;
                fh =1;
            }
        }
    }
    cout <<ans;
    return 0;
}

