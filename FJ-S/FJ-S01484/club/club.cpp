#include <cstdio>
#define isfileio 1
#define filename "club"
#define method 1
#if isfileio
#define programmefilein fopen(filename ".in", "r")
#define programmefileout fopen(filename ".out", "w")
#else
#define programmefilein stdin
#define programmefileout stdout
#endif
class fastInputHelper{
	char buf[1048577], *cn, *bufend;
	FILE *file;
	inline int getchar(){
		return cn != bufend ? *cn++ :
			(bufend = buf + fread(cn = buf, sizeof(char), 1048576llu, file), cn != bufend) ?
			*cn++ : ~0;
	}
	public:
		fastInputHelper(): cn(buf), bufend(buf), file(programmefilein){}
		~fastInputHelper(){
			fclose(file);
		}
		template<typename digit_type>
		fastInputHelper &operator>>(digit_type &x){
			int c = getchar();
			x = 0;
			while (c < 48 || c > 57){
				c = getchar();
				if (c == ~0){
					return *this;
				}
			}
			while (c > 47 && c < 58){
				x = x * 10 + (c & 15);
				c = getchar();
			}
			return *this;
		}
}fih;
class fastOutputHelper{
	char buf[1048577], *cn;
	const char *bufend;
	FILE *file;
	inline void putchar(int c){
		*cn++ = c;
		if (cn == bufend){
			fwrite(cn = buf, sizeof(char), 1048576llu, file);
		}
	}
	template<typename digit_type>
	void writedigit(const digit_type &x){
		if (x){
			writedigit(x / 10);
			putchar(x % 10 | 48);
		}
	}
	public:
		fastOutputHelper(): cn(buf), bufend(buf + 1048576llu), file(programmefileout){}
		~fastOutputHelper(){
			if (cn != buf){
				fwrite(buf, sizeof(char), cn - buf, file);
				cn = buf;
			}
			fclose(file);
		}
		template<typename digit_type>
		fastOutputHelper &operator<<(const digit_type &x){
			if (x > 0){
				writedigit(x / 10);
				putchar(x % 10 | 48);
			}
			else if(x == 0){
				putchar(48);
			}
			else{
				putchar('-');
				writedigit(-(x / 10));
				putchar(-(x % 10) | 48);
			}
			return *this;
		}
		inline fastOutputHelper &putc(int c){
			putchar(c);
		}
}foh;
#if method == 1
#include <queue>
#include <utility>
int a[100001][3], b[100001][3];
void swapint(int &a, int &b){
	a ^= b ^= a ^= b;
}
int main(){
	int t;
	fih >> t;
	while (t--){
		std::priority_queue<std::pair<int, int>> q[3];
		int len[3] = {0, 0, 0}, price = 0, n;
		fih >> n;
		for (int i = 0, n2 = n >> 1; i < n; ++i){
			int (&ai)[3] = a[i], (&bi)[3] = b[i];
			fih >> *ai >> ai[1] >> ai[2];
			*bi = 0;
			bi[1] = 1;
			bi[2] = 2;
			if (ai[*bi] < ai[bi[1]]){
				swapint(*bi, bi[1]);
			}
			if (ai[*bi] < ai[bi[2]]){
				swapint(*bi, bi[2]);
			}
			if (ai[bi[1]] < ai[bi[2]]){
				swapint(bi[1], bi[2]);
			}
			if (len[*bi] < n2){
				++len[*bi];
				q[*bi].emplace(ai[bi[1]] - ai[*bi], i);
				price += ai[*bi];
//				printf("%d\n", *bi);
				continue;
			}
			std::pair<int, int> p = q[*bi].top();
			int x = p.first + ai[*bi];
			if (x - ai[bi[1]] > 0){
				++len[b[p.second][1]];
				q[*bi].pop();
				q[*bi].emplace(ai[bi[1]] - ai[*bi], i);
				price += x;
//				printf("%d->%d\t%d\n", p.second, b[p.second][1], *bi);
			}
			else{
				++len[bi[1]];
				q[bi[1]].emplace(ai[bi[1]], i);
				price += ai[bi[1]];
//				printf("%d\n", bi[1]);
			}
		}
		foh << price;
		foh.putc(10);
	}
	return 0;
}
#endif
